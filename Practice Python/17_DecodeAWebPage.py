# https://www.practicepython.org/exercise/2014/06/06/17-decode-a-web-page.html

import requests
from bs4 import BeautifulSoup

url = 'https://www.foxnews.com/'
response = requests.get(url)

soup = BeautifulSoup(response.text, features="html.parser")
found_titles = soup.findAll('h2', 'title')

titles = [item.a.string for item in found_titles]

for index in range(10): # display first 10 articles
  print(f"{index + 1}. {titles[index]}")