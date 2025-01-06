import requests
from bs4 import BeautifulSoup

school_name = "um6p"
school_linkedin_url = f'https://ma.linkedin.com/school/{school_name}/'
response = requests.get(school_linkedin_url, proxies={'http': 'http://182.253.93.4'})


if response.status_code == 200:
    soup = BeautifulSoup(response.content, 'html.parser')
    posts_list = soup.find_all('li', {'class': 'mb-1'})

    if posts_list:
        posts = []
        for post in posts_list:

            post_content = post.find('p', {'class': 'attributed-text-segment-list__content'}).get_text().strip()
            post_time = post.find('time').get_text().strip()
            posts.append(f"Post Time: {post_time}\nPost Text: {post_content}\n{'=' * 50}\n")

        if posts:

            with open(f'{school_name}_posts.txt', "w+", encoding='utf-8') as file:
                file.write('\n'.join(posts))
            print(f"Posts saved to '{school_name}_posts.txt'")

    else:
        print("No posts found on the page.")

else:
    print(f"Error: Unable to fetch LinkedIn page (Status Code: {response.status_code})")