import discord,serial
from discord.ext.commands import Bot
import cv2

camera = cv2.VideoCapture(0)
intents = discord.Intents.all()
bot = Bot(command_prefix='!', intents=intents)
serport = serial.Serial("COM3", baudrate=9600, timeout=1)
@bot.event
async def on_ready():
    print('logged in as {0.user}'.format(bot))
 
@bot.command()
async def color(ctx, R:int, G:int, B:int):
    serport.write(f"c{R},{G},{B}".encode())
    await ctx.send("Light has changed, Use cam bot to see!")


@bot.command()
async def light(ctx,str):
    if(str.lower() == "on"):
        serport.write("o".encode())
        await ctx.send("Light has changed, Use cam bot to see!")
    if(str.lower() == "off"):
        serport.write("f".encode())
        await ctx.send("Light has changed, Use cam bot to see!")
    
@bot.command()
async def msg(ctx,str:str):
    serport.write(f"m{str}".encode())
    await ctx.send("message sent to display")

bot.run('')