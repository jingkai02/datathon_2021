from bs4 import BeautifulSoup
from bs4.element import ResultSet
import requests
import pandas as pd
import re

url = "https://guide.wisc.edu/undergraduate/letters-science/#degreesmajorscertificatestext"
page = requests.get(url)

text = BeautifulSoup(page.text, "html.parser")
with open("output1.html", "w",encoding='utf-8') as file:
    file.write(str(text))

pattern = re.compile(r'/undergraduate/letters-science/[^/]+/[^/]+/index')
Result = pattern.findall(str(text))

print(len(Result))
for x in Result:
    print(x)