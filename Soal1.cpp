#include <iostream>
#include <stack>
using namespace std;

// Definisi struktur node dari single linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Fungsi untuk mengecek apakah linked list adalah palindrome
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;  // Jika linked list kosong atau hanya satu elemen, otomatis palindrome
    
    ListNode* slow = head;
    ListNode* fast = head;
    stack<int> stk;

    // Gunakan 2 pointer, slow dan fast. Fast bergerak dua kali lebih cepat
    while (fast != NULL && fast->next != NULL) {
        stk.push(slow->val);  // Simpan nilai slow ke stack
        slow = slow->next;
        fast = fast->next->next;
    }

    // Jika jumlah elemen ganjil, lewati elemen tengah
    if (fast != NULL) {
        slow = slow->next;
    }

    // Sekarang, bandingkan elemen-elemen yang disimpan di stack dengan setengah kedua dari linked list
    while (slow != NULL) {
        int top = stk.top();
        stk.pop();

        // Jika ada yang tidak cocok, bukan palindrome
        if (slow->val != top) {
            return false;
        }
        slow = slow->next;
    }

    return true;
}

// Fungsi untuk menambahkan node baru di akhir linked list
void appendNode(ListNode*& head, int value) {
    if (head == NULL) {
        head = new ListNode(value);
    } else {
        ListNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new ListNode(value);
    }
}

// Fungsi untuk mencetak linked list (untuk pengecekan)
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen linked list: ";
    cin >> n;

    ListNode* head = NULL;

    // Input elemen-elemen dari linked list secara manual
    cout << "Masukkan elemen-elemen linked list: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        appendNode(head, value);
    }

    // Cetak linked list untuk pengecekan
    cout << "Linked list yang dibuat: ";
    printList(head);

    // Cek apakah linked list adalah palindrome
    if (isPalindrome(head)) {
        cout << "Output: true (linked list adalah palindrome)" << endl;
    } else {
        cout << "Output: false (linked list bukan palindrome)" << endl;
    }

    return 0;
}

/* Comments 1 */

/* Comment 2 */

/* comment 3 */