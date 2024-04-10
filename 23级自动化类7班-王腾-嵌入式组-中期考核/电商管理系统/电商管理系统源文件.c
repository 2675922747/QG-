#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��Ʒ�ṹ��
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// �û��ṹ��
typedef struct {
    char username[50];
    char password[50];
    float balance;
} User;

// �����ṹ��
typedef struct {
    int orderId;
    int productId;
    char productName[50];
    float productPrice;
    int quantity;
    float totalPrice;
    char address[100];
} Order;

// ��������
void addProduct(Product products[], int* count);
void displayProducts(Product products[], int count);
void registerUser(User* user);
void login(User* user);
void searchProduct(Product products[], int count);
void purchaseProduct(Product products[], int count, User* user);
void generateOrder(Product products[], int count, User* user);



int main() {
    Product products[100]; // ���洢100����Ʒ
    int productCount = 0;
    User user;
    int choice;
  


    // �û�ע��
    registerUser(&user);


 


    do {
        // ��ʾ�˵�
        printf("\n=== ���̹���ϵͳ ===\n");
        printf("1. ��Ӳ�Ʒ\n");
        printf("2. ��ʾ��Ʒ\n");
        printf("3. ������Ʒ\n");
        printf("4. �����Ʒ\n");
        printf("5. ���ɶ���\n");
        printf("6. �û���ֵ\n");
        printf("0. �˳�\n");
        printf("��ѡ�����: ");
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
            printf("�˳�����.\n");
            break;
        default:
            printf("��Чѡ�������ѡ��.\n");
        }
    } while (choice != 0);

    return 0;
}




// ��Ӳ�Ʒ
void addProduct(Product products[], int* count) {
    if (*count >= 100) {
        printf("��Ʒ���������޷�����²�Ʒ��\n");
        return;
    }

    printf("�������Ʒ����: ");
    scanf_s(" %[^\n]", products[*count].name, sizeof(products[*count].name));

    printf("�������Ʒ�۸�: ");
    while (scanf_s("%f", &products[*count].price) != 1 || products[*count].price <= 0) {
        printf("�۸������һ������������������: ");
        while (getchar() != '\n'); // ������뻺����
    }

    printf("�������Ʒ����: ");
    while (scanf_s("%d", &products[*count].quantity) != 1 || products[*count].quantity <= 0) {
        printf("����������һ��������������������: ");
        while (getchar() != '\n'); // ������뻺����
    }

    products[*count].id = *count + 1; // �Զ����ɲ�ƷID
    (*count)++; // ���Ӳ�Ʒ����
    printf("��Ʒ��ӳɹ���\n");
}
//��ȡ��Ʒ�����ơ��۸�����������Լ۸��������������֤��ȷ�����Ƕ��ǺϷ������֡��������ļ۸���������Ϸ��������ʾ�û��������롣






    // ��ʾ��Ʒ
void displayProducts(Product products[], int count) {
    if (count == 0) {
        printf("���޲�Ʒ��Ϣ��\n");
        return;
    }

    printf("\n=== ��Ʒ�б� ===\n");
    printf("ID\t����\t\t�۸�\t����\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}
//����������У������Ʒ�б�Ϊ�գ���������һ����ʾ��Ϣ"���޲�Ʒ��Ϣ��"��Ȼ��ֱ�ӷ��أ����ټ���ִ����ʾ��Ʒ�Ĳ��������������ṩ���Ѻõ��û����飬����û�в�Ʒ����ʾʱ�ṩ��ȷ�ķ�����



// �û�ע��
void registerUser(User users[], int* userCount) {
    char username[50];
    char password[50];
    char confirmPassword[50];

    printf("=== �û�ע�� ===\n");
    printf("�������û���: ");
    scanf_s(" %[^\n]", username, sizeof(username));

    // ����û����Ƿ��Ѵ���
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("�û����Ѵ��ڣ�������ѡ��\n");
            return;
        }
    }

    // ��������
    printf("����������: ");
    scanf_s(" %[^\n]", password, sizeof(password));

    // ȷ������
    printf("���ٴ�����������ȷ��: ");
    scanf_s(" %[^\n]", confirmPassword, sizeof(confirmPassword));

    // ��������Ƿ�һ��
    if (strcmp(password, confirmPassword) != 0) {
        printf("������������벻һ�£�������ע�ᡣ\n");
        return;
    }

    // ���û���Ϣ�洢���û�������
    strcpy_s(users[*userCount].username, sizeof(users[*userCount].username), username);
    strcpy_s(users[*userCount].password, sizeof(users[*userCount].password), password);
    (*userCount)++;

    printf("ע��ɹ���\n");
}
// �û������û���������󣬳�������û����Ƿ��Ѿ����ڣ�Ȼ��Ҫ���û�ȷ�����롣�������ȷ��һ�£����û���Ϣ�洢���û������У��������û�������



// �û���¼

void login(User* user) {
    char username[50];
    char password[50];

    printf("=== �û���¼ ===\n");
    printf("�������û���: ");
    scanf_s(" %[^\n]", username, sizeof(username));
    printf("����������: ");
    scanf_s(" %[^\n]", password, sizeof(password));

    // ������һ����ע����û���Ϣ�б������Ϊ�����û�
    if (strcmp(username, user->username) == 0 && strcmp(password, user->password) == 0) {
        printf("��¼�ɹ���\n");
    }
    else {
        printf("�û������������\n");
    }
}

//�û������û���������󣬳������Ԥ��ע����û���Ϣ���бȽϡ�����û���������ƥ�䣬�������¼�ɹ�����Ϣ����������û���������������Ϣ��



// ������Ʒ
void searchProduct(Product products[], int count) {
    char searchName[50];
    int found = 0;

    printf("������Ҫ�����Ĳ�Ʒ����: ");
    scanf_s(" %[^\n]", searchName, sizeof(searchName));

    printf("\n�������:\n");
    printf("ID\t����\t\t�۸�\t����\n");
    for (int i = 0; i < count; i++) {
        if (strstr(products[i].name, searchName) != NULL) {
            printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("δ�ҵ�ƥ��Ĳ�Ʒ��\n");
    }
}
//�û�����Ҫ�����Ĳ�Ʒ���ƺ󣬳���������Ʒ�б��ҵ����ư��������ؼ��ʵĲ�Ʒ�������������������δ�ҵ�ƥ��Ĳ�Ʒ���������ʾ��Ϣ"δ�ҵ�ƥ��Ĳ�Ʒ��"��





// �����Ʒ
void purchaseProduct(Product products[], int count, User* user) {
    int productId;
    int quantity;

    printf("������Ҫ����Ĳ�ƷID: ");
    scanf_s("%d", &productId);

    // ���Ҳ�Ʒ�Ƿ����
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (products[i].id == productId) {
            found = 1;
            printf("��ѡ����Ĳ�Ʒ��Ϣ����:\n");
            printf("����: %s\n", products[i].name);
            printf("�۸�: %.2f\n", products[i].price);
            printf("����: %d\n", products[i].quantity);

            // ���빺������
            printf("�����빺������: ");
            scanf_s("%d", &quantity);

            // ��鹺�������Ƿ�Ϸ�
            if (quantity <= 0 || quantity > products[i].quantity) {
                printf("����������Ч�򳬹���棬������ѡ��\n");
                return;
            }

            // ����û�����Ƿ��㹻
            float totalCost = products[i].price * quantity;
            if (user->balance < totalCost) {
                printf("���㣬���ֵ���ٹ���\n");
                return;
            }

            // ���²�Ʒ�������û����
            products[i].quantity -= quantity;
            user->balance -= totalCost;
            printf("����ɹ���\n");
            return;
        }
    }

    if (!found) {
        printf("δ�ҵ�ָ��ID�Ĳ�Ʒ��\n");
    }
}
//����������û�����Ҫ����Ĳ�ƷID��Ȼ����ò�Ʒ�Ƿ���ڡ������Ʒ���ڣ��������ʾ��Ʒ��Ϣ��ѯ���û�����������Ȼ���鹺�������Ƿ�Ϸ����Լ��û�����Ƿ��㹻֧�������һ���������������²�Ʒ�������û������������ɹ�����Ϣ��






//���ɶ���
void generateOrder(Product products[], int count, User* user) {
    static int orderIdCounter = 1; // �����ż���������̬�������ֳ־���

    int productId;
    int quantity;
    Order order;

    printf("������Ҫ����Ĳ�ƷID: ");
    scanf_s("%d", &productId);

    // ���Ҳ�Ʒ�Ƿ����
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (products[i].id == productId) {
            found = 1;
            printf("��ѡ����Ĳ�Ʒ��Ϣ����:\n");
            printf("����: %s\n", products[i].name);
            printf("�۸�: %.2f\n", products[i].price);
            printf("����: %d\n", products[i].quantity);

            // ���빺������
            printf("�����빺������: ");
            scanf_s("%d", &quantity);

            // ��鹺�������Ƿ�Ϸ�
            if (quantity <= 0 || quantity > products[i].quantity) {
                printf("����������Ч�򳬹���棬������ѡ��\n");
                return;
            }

            // ���ɶ�����
            order.orderId = orderIdCounter++;

            // ��д������Ϣ
            order.productId = products[i].id;
            strcpy_s(order.productName, sizeof(order.productName), products[i].name);
            order.productPrice = products[i].price;
            order.quantity = quantity;
            order.totalPrice = order.productPrice * order.quantity;

            // �������͵�ַ
            printf("���������͵�ַ: ");
            scanf_s(" %[^\n]", order.address, sizeof(order.address));

            // �洢������Ϣ���˴�ʡ�ԣ�

            printf("�������ɳɹ���\n");
            return;
        }
    }

    if (!found) {
        printf("δ�ҵ�ָ��ID�Ĳ�Ʒ��\n");
    }
}
//����������û�����Ҫ����Ĳ�ƷID��Ȼ����ò�Ʒ�Ƿ���ڡ������Ʒ���ڣ��������ʾ��Ʒ��Ϣ��ѯ���û��������������͵�ַ��Ȼ�����ɶ����Ų���д������Ϣ���������������ɳɹ�����Ϣ��




// ��ֵ
void recharge(User* user) {
    float amount;

    printf("�������ֵ���: ");
    scanf_s("%f", &amount);

    if (amount <= 0) {
        printf("��ֵ���������0��\n");
        return;
    }

    // �����û����
    user->balance += amount;
    printf("��ֵ�ɹ�����ǰ���Ϊ: %.2f\n", user->balance);
}

