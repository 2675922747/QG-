#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 产品结构体
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// 用户结构体
typedef struct {
    char username[50];
    char password[50];
    float balance;
} User;

// 订单结构体
typedef struct {
    int orderId;
    int productId;
    char productName[50];
    float productPrice;
    int quantity;
    float totalPrice;
    char address[100];
} Order;

// 函数声明
void addProduct(Product products[], int* count);
void displayProducts(Product products[], int count);
void registerUser(User* user);
void login(User* user);
void searchProduct(Product products[], int count);
void purchaseProduct(Product products[], int count, User* user);
void generateOrder(Product products[], int count, User* user);



int main() {
    Product products[100]; // 最多存储100个产品
    int productCount = 0;
    User user;
    int choice;
  


    // 用户注册
    registerUser(&user);


 


    do {
        // 显示菜单
        printf("\n=== 电商管理系统 ===\n");
        printf("1. 添加产品\n");
        printf("2. 显示产品\n");
        printf("3. 搜索产品\n");
        printf("4. 购买产品\n");
        printf("5. 生成订单\n");
        printf("6. 用户充值\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addProduct(products, &productCount);
            break;
        case 2:
            displayProducts(products, productCount);
            break;
        case 3:
            searchProduct(products, productCount);
            break;
        case 4:
            purchaseProduct(products, productCount, &user);
            break;
        case 5:
            generateOrder(products, productCount, &user);
            break;
        case 0:
            printf("退出程序.\n");
            break;
        default:
            printf("无效选项，请重新选择.\n");
        }
    } while (choice != 0);

    return 0;
}




// 添加产品
void addProduct(Product products[], int* count) {
    if (*count >= 100) {
        printf("产品库已满，无法添加新产品。\n");
        return;
    }

    printf("请输入产品名称: ");
    scanf_s(" %[^\n]", products[*count].name, sizeof(products[*count].name));

    printf("请输入产品价格: ");
    while (scanf_s("%f", &products[*count].price) != 1 || products[*count].price <= 0) {
        printf("价格必须是一个正数，请重新输入: ");
        while (getchar() != '\n'); // 清空输入缓冲区
    }

    printf("请输入产品数量: ");
    while (scanf_s("%d", &products[*count].quantity) != 1 || products[*count].quantity <= 0) {
        printf("数量必须是一个正整数，请重新输入: ");
        while (getchar() != '\n'); // 清空输入缓冲区
    }

    products[*count].id = *count + 1; // 自动生成产品ID
    (*count)++; // 增加产品数量
    printf("产品添加成功。\n");
}
//读取产品的名称、价格和数量，并对价格和数量进行了验证，确保它们都是合法的数字。如果输入的价格或数量不合法，则会提示用户重新输入。






    // 显示产品
void displayProducts(Product products[], int count) {
    if (count == 0) {
        printf("暂无产品信息。\n");
        return;
    }

    printf("\n=== 产品列表 ===\n");
    printf("ID\t名称\t\t价格\t数量\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}
//在这个代码中，如果产品列表为空，程序会输出一条提示信息"暂无产品信息。"，然后直接返回，不再继续执行显示产品的操作。这样可以提供更友好的用户体验，并在没有产品可显示时提供明确的反馈。



// 用户注册
void registerUser(User users[], int* userCount) {
    char username[50];
    char password[50];
    char confirmPassword[50];

    printf("=== 用户注册 ===\n");
    printf("请输入用户名: ");
    scanf_s(" %[^\n]", username, sizeof(username));

    // 检查用户名是否已存在
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("用户名已存在，请重新选择。\n");
            return;
        }
    }

    // 输入密码
    printf("请输入密码: ");
    scanf_s(" %[^\n]", password, sizeof(password));

    // 确认密码
    printf("请再次输入密码以确认: ");
    scanf_s(" %[^\n]", confirmPassword, sizeof(confirmPassword));

    // 检查密码是否一致
    if (strcmp(password, confirmPassword) != 0) {
        printf("两次输入的密码不一致，请重新注册。\n");
        return;
    }

    // 将用户信息存储到用户数组中
    strcpy_s(users[*userCount].username, sizeof(users[*userCount].username), username);
    strcpy_s(users[*userCount].password, sizeof(users[*userCount].password), password);
    (*userCount)++;

    printf("注册成功。\n");
}
// 用户输入用户名和密码后，程序会检查用户名是否已经存在，然后要求用户确认密码。如果密码确认一致，则将用户信息存储到用户数组中，并增加用户数量。



// 用户登录

void login(User* user) {
    char username[50];
    char password[50];

    printf("=== 用户登录 ===\n");
    printf("请输入用户名: ");
    scanf_s(" %[^\n]", username, sizeof(username));
    printf("请输入密码: ");
    scanf_s(" %[^\n]", password, sizeof(password));

    // 假设有一个已注册的用户信息列表，这里简化为单个用户
    if (strcmp(username, user->username) == 0 && strcmp(password, user->password) == 0) {
        printf("登录成功。\n");
    }
    else {
        printf("用户名或密码错误。\n");
    }
}

//用户输入用户名和密码后，程序会与预先注册的用户信息进行比较。如果用户名和密码匹配，则输出登录成功的消息；否则输出用户名或密码错误的消息。



// 搜索产品
void searchProduct(Product products[], int count) {
    char searchName[50];
    int found = 0;

    printf("请输入要搜索的产品名称: ");
    scanf_s(" %[^\n]", searchName, sizeof(searchName));

    printf("\n搜索结果:\n");
    printf("ID\t名称\t\t价格\t数量\n");
    for (int i = 0; i < count; i++) {
        if (strstr(products[i].name, searchName) != NULL) {
            printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("未找到匹配的产品。\n");
    }
}
//用户输入要搜索的产品名称后，程序会遍历产品列表，找到名称包含搜索关键词的产品，并输出搜索结果。如果未找到匹配的产品，则输出提示信息"未找到匹配的产品。"。





// 购买产品
void purchaseProduct(Product products[], int count, User* user) {
    int productId;
    int quantity;

    printf("请输入要购买的产品ID: ");
    scanf_s("%d", &productId);

    // 查找产品是否存在
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (products[i].id == productId) {
            found = 1;
            printf("您选择购买的产品信息如下:\n");
            printf("名称: %s\n", products[i].name);
            printf("价格: %.2f\n", products[i].price);
            printf("数量: %d\n", products[i].quantity);

            // 输入购买数量
            printf("请输入购买数量: ");
            scanf_s("%d", &quantity);

            // 检查购买数量是否合法
            if (quantity <= 0 || quantity > products[i].quantity) {
                printf("购买数量无效或超过库存，请重新选择。\n");
                return;
            }

            // 检查用户余额是否足够
            float totalCost = products[i].price * quantity;
            if (user->balance < totalCost) {
                printf("余额不足，请充值后再购买。\n");
                return;
            }

            // 更新产品数量和用户余额
            products[i].quantity -= quantity;
            user->balance -= totalCost;
            printf("购买成功。\n");
            return;
        }
    }

    if (!found) {
        printf("未找到指定ID的产品。\n");
    }
}
//程序会先让用户输入要购买的产品ID，然后检查该产品是否存在。如果产品存在，程序会显示产品信息并询问用户购买数量。然后检查购买数量是否合法，以及用户余额是否足够支付。如果一切正常，程序会更新产品数量和用户余额，并输出购买成功的消息。






//生成订单
void generateOrder(Product products[], int count, User* user) {
    static int orderIdCounter = 1; // 订单号计数器，静态变量保持持久性

    int productId;
    int quantity;
    Order order;

    printf("请输入要购买的产品ID: ");
    scanf_s("%d", &productId);

    // 查找产品是否存在
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (products[i].id == productId) {
            found = 1;
            printf("您选择购买的产品信息如下:\n");
            printf("名称: %s\n", products[i].name);
            printf("价格: %.2f\n", products[i].price);
            printf("数量: %d\n", products[i].quantity);

            // 输入购买数量
            printf("请输入购买数量: ");
            scanf_s("%d", &quantity);

            // 检查购买数量是否合法
            if (quantity <= 0 || quantity > products[i].quantity) {
                printf("购买数量无效或超过库存，请重新选择。\n");
                return;
            }

            // 生成订单号
            order.orderId = orderIdCounter++;

            // 填写订单信息
            order.productId = products[i].id;
            strcpy_s(order.productName, sizeof(order.productName), products[i].name);
            order.productPrice = products[i].price;
            order.quantity = quantity;
            order.totalPrice = order.productPrice * order.quantity;

            // 输入配送地址
            printf("请输入配送地址: ");
            scanf_s(" %[^\n]", order.address, sizeof(order.address));

            // 存储订单信息（此处省略）

            printf("订单生成成功。\n");
            return;
        }
    }

    if (!found) {
        printf("未找到指定ID的产品。\n");
    }
}
//程序会先让用户输入要购买的产品ID，然后检查该产品是否存在。如果产品存在，程序会显示产品信息并询问用户购买数量和配送地址。然后生成订单号并填写订单信息，最后输出订单生成成功的消息。




// 充值
void recharge(User* user) {
    float amount;

    printf("请输入充值金额: ");
    scanf_s("%f", &amount);

    if (amount <= 0) {
        printf("充值金额必须大于0。\n");
        return;
    }

    // 更新用户余额
    user->balance += amount;
    printf("充值成功，当前余额为: %.2f\n", user->balance);
}

