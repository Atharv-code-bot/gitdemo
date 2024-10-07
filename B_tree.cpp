// Pseudo code


//   struct node
//         datatypes for content...
//         int children
//         struct node *next [children]
//     struct node* head = NULL
//     struct node* p = NULL
//     struct node* n = NULL
//     head = malloc(sizeof *head);
//     int children = input a value
//     for i in length of children
//         head→next[i] = malloc(sizeof(struct node));
//         head→next = malloc(sizeof(struct node));
//         p = head→next;
//         p→content = malloc(sizeof content);
//     while (...)
//         input content
//         p→next = malloc(sizeof(struct node))
//         n = p→next;
//         n→children = input a value
//         for i in length of children
//                p→next[i] = malloc(sizeof(struct node))
//                p→content = malloc(sizeof content)
//                p=n
