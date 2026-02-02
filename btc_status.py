import requests
# Fetch the latest Bitcoin block height from a public API
response = requests.get("https://blockchain.info/latestblock")
data = response.json()
print(f"Current Bitcoin Block Height: {data['height']}")
