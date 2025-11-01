def search(nums, target):
    try
        return nums.index(target)
    except ValueError:
        return -1

if __name__ == "__main__":
    nums = [1, 3, 5, 7, 9, 5]
    target = int(input("Enter target value: "))
    index = search(nums, target)

    if index != -1:
        print(f"Target {target} found at index: {index}")
    else:
        print(f"Target {target} not found.")
