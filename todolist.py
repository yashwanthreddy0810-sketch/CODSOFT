tasks = []
while True:
    print("\n===== TO-DO LIST MENU =====")
    print("1. View Tasks")
    print("2. Add Task")
    print("3. Mark Task as Completed")
    print("4. Delete Task")
    print("5. Exit")
    choice = input("Enter your choice (1-5): ")
    if choice == '1':
        if len(tasks) == 0:
            print("No tasks available.")
        else:
            print("\nYour Tasks:")
            for i, task in enumerate(tasks, start=1):
                status = "✓" if task["completed"] else "✗"
                print(f"{i}. {task['name']} [{status}]")
    elif choice == '2':
        task_name = input("Enter task: ")
        tasks.append({"name": task_name, "completed": False})
        print("Task added successfully!")
    elif choice == '3':
        if len(tasks) == 0:
            print("No tasks available.")
        else:
            for i, task in enumerate(tasks, start=1):
                print(f"{i}. {task['name']}")
            try:
                task_num = int(input("Enter task number to mark as completed: "))
                tasks[task_num - 1]["completed"] = True
                print("Task marked as completed")
            except (ValueError, IndexError):
                print("Invalid task number.")
    elif choice == '4':
        if len(tasks) == 0:
            print("No tasks available.")
        else:
            for i, task in enumerate(tasks, start=1):
                print(f"{i}. {task['name']}")
            try:
                task_num = int(input("Enter task number to delete: "))
                removed = tasks.pop(task_num - 1)
                print(f"Task '{removed['name']}' deleted.")
            except (ValueError, IndexError):
                print("Invalid task number.")
    elif choice == '5':
        print("Thank you for using To-Do List Application!")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 5.")
