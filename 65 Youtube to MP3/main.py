from __future__ import unicode_literals
import youtube_dl
import sys

ydl_opts = {
    'format': 'bestaudio/best',
    'postprocessors': [{
        'key': 'FFmpegExtractAudio',
        'preferredcodec': 'mp3',
        'preferredquality': '192',
    }],
}

link = sys.argv[1] if len(sys.argv) > 1 else input("Enter video adress: ")

with youtube_dl.YoutubeDL(ydl_opts) as ydl:
    ydl.download([link])
