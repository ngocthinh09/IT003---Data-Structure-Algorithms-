#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void Nhap(DATHUC &B, double heso, double somu){
    DONTHUC* newDONTHUC = new DONTHUC(heso, somu);
    Node* newNode = new Node(newDONTHUC);

    if (B.head == NULL){
        B.head = B.tail = newNode;
    }
    else{
        B.tail->next = newNode;
        B.tail = newNode;
    }
}

double TinhDaThuc(DATHUC B, double x){
    double res = 0;
    Node* current = B.head;

    while (current != NULL){
        double heso = current->data->heso;
        int somu = current->data->somu;
        res += (double)heso*pow(x, somu);
        current = current->next;
    }
    return res;
}

void Xuat(DATHUC B){
    Node* current = B.head;
    bool first = true;

    while (current != NULL){
        double heso = current->data->heso;
        int somu = current->data->somu;
        
        if (heso == 0)
            current = current->next;
        else if (heso > 0){
            if (heso != 1 || somu == 0){
                if (!first)  cout << "+";
                cout << heso;
                first = false;
            }
            else if (heso == 1 && somu > 0){
                if (!first)  cout << "+";
                first = false;
            }
            if (somu > 0){
                cout << "x";
                first = false;
                if (somu > 1)
                    cout << "^" << somu;
            }
            current = current->next;
        }
        else if (heso < 0){
            if (heso != -1 || somu == 0) {
                cout << heso;
                first = false;
            }
            else if (heso == -1 && somu > 0){
                cout << "-";
                first = false;
            }
            if (somu > 0){
                cout << "x";
                first = false;
                if (somu > 1)
                    cout << "^" << somu;
            }
            current = current->next;
        }
        
    }
    if (first)
        cout << 0;
    
}

int main() {
    if (fopen("test.inp", "r")){
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    }

    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
