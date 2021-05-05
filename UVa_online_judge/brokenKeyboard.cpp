#include <iostream>

using namespace std;

template<class T> struct LinkedList {
    
    struct Node {
        Node * next;
        T data;
        Node(T val) {
            next = NULL;
            data = val;
        }
    };
    
    Node * head;
    Node * tail;
    int size;
    
    LinkedList() {
        tail = head = NULL;
        size = 0;
    }
    
    //Agregar
    void push_back(T val) {
        Node * node = new Node(val);
        if (size == 0) {
            tail = head = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        size++;
    }
    
    //Quitar
    void pop_back() {
        if (size == 0) {
            throw runtime_error("Cannot erase from the empty list");
        }
        if (size == 1) {
            head = tail = NULL;
        }
        else {
            Node * prev = head;
            Node * last = head->next;
            while (last && last->next) {
                last = last->next;
                prev = prev->next;
            }
            prev->next = NULL;
            tail = prev;
        }
        size--;
    }
    
    //Buscar
    bool exists(T val) {
        if (size == 0) {
            return false;
        }
        Node * current = head;
        while (current) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    
    
    //Esta función no se la fusile a quick xD, es para imprimir
    void impresion(LinkedList<char> *list){ //Pasamos de parametro la lista a imprimir
        
        //cout<<"Entra a la funcion IMprimir\n";
        Node *imp;
        imp = list->head;
        if(imp != NULL) //Imprimir siempre y cuano la lista no este vacia
        {
            //cout<<"Imprimir-entra if\n";
            while(imp != NULL)
            {
                //cout<<"\nindicator\n";
                if(imp->data != ']' && imp->data != '[')//NO imprimirmos los caracters de home, end
                    cout<<imp->data; //Imprmimir los elementos
                
                imp = imp->next; //Recorrer la lista
            }
            
            //cout<<list->head->data;
            
        }else {cout<<"Tu lista esta vacia\n";}
        
    }//Termina func impresion
    
    
    
    
    //Esta tampoco me la fusile
    /*FUNCION PARA HACER UNA ESPECIE DE MERGE; DONDE LOS PRIMEROS ELEMENTOS DE LA LISTA SEAN HEAD; DESPUES BEIJU*/
    LinkedList<char>* changeHome (LinkedList<char>* Beiju/*Donde esta el texto chido*/, LinkedList<char>* head/*Lista auxiliar*/)
    {
        //cout<<"Entra a la funcion Home\n";
        
        
        LinkedList<char> *nuevoBeiju = new LinkedList<char>();
        
        Node *auxHead;
        
        nuevoBeiju->head = head->head;
        auxHead = head->tail;

        auxHead->next = Beiju->head;
        nuevoBeiju->tail = Beiju->tail;
        
        Beiju->head = NULL;
        head->head = NULL;
        Beiju->tail = NULL;
        head->tail = NULL;
        head->size = 0;
        /*Explicar, que carajo hize xD*/
        return nuevoBeiju;
        
    }
    
    //Tampoco esta funcion
    /*FUNCION PARA HACER UNA ESPECIE DE MERGE; DONDE LOS PRIMEROS ELEMENTOS DE LA LISTA SEAN BEIJU; DESPUES TAIL*/
    LinkedList<char>* changeEnd (LinkedList<char>*Beiju, LinkedList<char>*tail)
    {

        LinkedList<char> *nuevoBeiju = new LinkedList<char>();
        
        Node *auxTail;
        
        nuevoBeiju->head = Beiju->head;
        auxTail = Beiju->tail;

        auxTail->next = tail->head;
        nuevoBeiju->tail = tail->tail;
        
        //cout<<"Van los valores en NULL\n";
        Beiju->head = NULL;
        tail->head = NULL;
        Beiju->tail = NULL;
        tail->tail = NULL;
        tail->size = 0;

        
        return nuevoBeiju;
        
    }
    
    
    
}; //Termina Linked List implementation




/*FUNCION MAIN*/
int main() {
    
    string line;
    while (getline(cin,line) && line[0] != '0') { //Lee la line completa para procesarla
        
        LinkedList<char> *Beiju = new LinkedList<char>();
        LinkedList<char> *head = new LinkedList<char>();
        LinkedList<char> *tail = new LinkedList<char>();
        int ban = 0;
        
        for(int i = 0; i<line.size(); i++) //Desde aqui empieza el proceso de agarrar caracter por caracter
        {
            
            //Guardar las varibales en las listas correspondientes
            if(ban == 1)
                head->push_back(line[i]);
            else if(ban == 2)
                tail->push_back(line[i]);
            else if(ban == 0)
                Beiju->push_back(line[i]);
            
            
            //EVALUACION DEL CARACTER QUE ENTRO A LA LISTA
            
            if(line[i] == '[' || i == (line.size()-1))//Home, inicio de texto, si el char es ] o si i es igual al ultimo carater del string, si se cumple cualquiera de las dos, se realiza el intercambio en caso de que head->head no sea NULL
            {
                
                /*IMPRESION DE BEIJU Y HEAD
                 cout<<"Impresion de Beiju = ";
                 Beiju->impresion(Beiju); cout<<endl;
                 cout<<"IMpresion de head = ";
                 head->impresion(head); cout<<endl;*/
                //cout<<"Entra al if"<<endl;
                //Evaluamos que Beiju tenga elementos
                if(head->head != NULL)
                {
                    Beiju = Beiju->changeHome(Beiju, head);
  
                }
                
                if(tail->head != NULL)
                {
                    Beiju = Beiju->changeEnd(Beiju, tail);
  
                }
                //LEvantamos la bandera para guardar en head;
                ban = 1;

                
            } else if (line[i] == ']' || i == (line.size()-1))//End, fin de texto, si el char es [ o si i es igual al ultimo carater del string, si se cumple cualquiera de las dos, se realiza el intercambio en caso de que
            {
                //cout<<"Entra al if"<<endl;
                /*PARTE DE IMPRESION*/
                /*cout<<"Impresion de Beiju = ";
                 Beiju->impresion(Beiju); cout<<endl;
                 cout<<"IMpresion de head = ";
                 head->impresion(head); cout<<endl;*/
                
                if(tail->head != NULL)
                {
                    Beiju = Beiju->changeEnd(Beiju, tail);

                }
                
                if(head->head != NULL)
                {
                    Beiju = Beiju->changeHome(Beiju, head);

                }
                ban = 2;

            }
            
            /*cout<<"Por cada iteracion =\n";
            Beiju->impresion(Beiju);
            cout<<endl;
            head->impresion(head);
            cout<<endl;
            tail->impresion(tail);
            cout<<endl;*/
            
        }
        
        //cout<<"\nIMpresion final\n";
        Beiju->impresion(Beiju);
        cout<<endl;

    }
    
    return 0;
}
