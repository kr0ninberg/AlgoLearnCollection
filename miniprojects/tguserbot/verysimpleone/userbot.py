import os
from dotenv import load_dotenv
from telethon import TelegramClient, events

load_dotenv()

API_ID = int(os.getenv("TG_API_ID"))
API_HASH = os.getenv("TG_API_HASH")

client = TelegramClient("test1", API_ID, API_HASH)

@client.on(events.NewMessage(outgoing=True, pattern=r"\.ping$"))
async def ping_handler(event):
    await event.edit("pong ✅")

@client.on(events.NewMessage(outgoing=True, pattern=r"\.echo (.+)"))
async def echo_handler(event):
    text = event.pattern_match.group(1)
    await event.edit(text)

def main():
    client.start()  # при первом запуске попросит номер и код из Telegram
    print("Userbot запущен. Команды: .ping, .echo <текст>")
    client.run_until_disconnected()

if __name__ == "__main__":
    main()