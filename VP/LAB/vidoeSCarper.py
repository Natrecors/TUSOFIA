import yt_dlp

def download_youtube_max_quality(url):
    ydl_opts = {
        # --- MAX QUALITY SETTINGS ---
        'format': 'bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]/best',
        'outtmpl': '%(title)s.%(ext)s',
        'quiet': False,
        'no_warnings': True,
        
        # --- THE 403 FIX ---
        # NO COOKIES: We removed 'cookiesfrombrowser' because it conflicts with the mobile spoof.
        # STRICT MOBILE: We removed 'web' from the client list. It will only pretend to be an Android/iOS app.
        'extractor_args': {
            'youtube': ['player_client=android,ios']
        },
    }

    try:
        print(f"Fetching MAX QUALITY video from: {url}")
        with yt_dlp.YoutubeDL(ydl_opts) as ydl:
            ydl.download([url])
        print("Video downloaded successfully!")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    target_url = "https://www.youtube.com/watch?v=bC2Fa-Id6UY"
    
    download_youtube_max_quality(target_url)