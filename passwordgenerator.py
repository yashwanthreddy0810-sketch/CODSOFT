import string
import secrets
def generate_password(length, use_upper, use_digits, use_special):
    char_pool = string.ascii_lowercase
    if use_upper:
        char_pool += string.ascii_uppercase
    if use_digits:
        char_pool += string.digits
    if use_special:
        char_pool += string.punctuation
    return "".join(secrets.choice(char_pool) for _ in range(length))
def main():
    print("--- Secure Password Generator ---")
    try:
        length = int(input("Enter the desired password length: "))
        if length < 4:
            print("Security warning: Length should be at least 4. Setting to 4.")
            length = 4
    except ValueError:
        print("Invalid input. Defaulting length to 12.")
        length = 12
    print("\nConfigure password complexity:")
    use_upper = input("Include uppercase letters? (y/n): ").lower() == "y"
    use_digits = input("Include numbers? (y/n): ").lower() == "y"
    use_special = input("Include special characters? (y/n): ").lower() == "y"
    password = generate_password(length, use_upper, use_digits, use_special)
    print("\n" + "=" * 30)
    print(f"Generated Password: {password}")
    print("=" * 30)
if __name__ == "__main__":
    main()
