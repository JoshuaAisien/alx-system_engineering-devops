#!/usr/bin/python3
"""Returns to-do list information for a given employee ID."""
import requests
import sys


def get_employee_todo_progress(employee_id):
    # URLs for the API endpoints
    user_url = f'https://jsonplaceholder.typicode.com/users/{employee_id}'
    todos_url = f'https://jsonplaceholder.typicode.com/todos?userId={employee_id}'

    try:
        # Fetch user information
        user_response = requests.get(user_url)
        user_response.raise_for_status()  # Raise an HTTPError for bad responses
        user_data = user_response.json()
        employee_name = user_data['name']

        # Fetch TODO list
        todos_response = requests.get(todos_url)
        todos_response.raise_for_status()
        todos_data = todos_response.json()

        # Calculate completed and total tasks
        total_tasks = len(todos_data)
        done_tasks = [task for task in todos_data if task['completed']]
        number_of_done_tasks = len(done_tasks)

        # Print the progress
        print(f"Employee {employee_name} is done with tasks({number_of_done_tasks}/{total_tasks}):")
        for task in done_tasks:
            print(f"\t {task['title']}")

    except requests.exceptions.RequestException as e:
        print(f"HTTP Request failed: {e}")
    except KeyError as e:
        print(f"Unexpected response format: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <employee_id>")
    else:
        try:
            employee_id = int(sys.argv[1])
            get_employee_todo_progress(employee_id)
        except ValueError:
            print("Employee ID must be an integer.")