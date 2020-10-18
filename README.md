# list
My implementation of lists

## Init list with type int:
```List<int> list;```

## Append to list 1:
```list.append(1);```

## Pop first element:
```list.pop(0);```

## Clear list:
```list.clear();```

## Get length of the list:
```list.length();```

## There is also a head and a tail
```list.head();

list.tail();
```

# Example:
```List<int> list;

for(int i = 0; i < 10; i++)
{
    list.append(i);
}

for(int i = 0; i < list.length(); i++)
{
    std::cout << list[i] << std::endl;
}
```
## Output:
0
1
2
3
4
5
6
7
8
9