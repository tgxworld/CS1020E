#include <iostream>
#include <string>

using namespace std;

class Animal {
  private:
    string _name, _sound;
  public:
    Animal(string name, string sound) : _name(name), _sound(sound) {

    }

    string get_name() {
      return _name;
    }

    string get_sound() {
      return _sound;
    }
};

class OldMacdonald {
  private:
    Animal *_farm;
    int _size;
  public:
    OldMacdonald(int size, Animal *farm) : _farm(farm), _size(size) {

    }

    void sing() {
      for(int i = 0; i < this->_size; ++i) {
        string sound = _farm[i].get_sound();
        string name = _farm[i].get_name();

        if(i != 0) cout << endl;
        cout << "Old Macdonald had a farm, E-I-E-I-O" << endl;
        cout << "and on his farm he had a " << name << ", E-I-E-I-O" << endl;
        cout << "with a " << sound << " " << sound << " here and a " << sound << " " << sound << " there" << endl;
        cout << "here a " << sound << ", there a " << sound << ", everywhere a " << sound << " " << sound << endl;
        cout << "Old Macdonald had a farm, E-I-E-I-O" << endl;
      }
    }
};

int main() {
  Animal cow("Cow", "Moo");
  Animal dog("Dog", "Woof");
  Animal duck("Duck", "Quack");
  Animal farm[3] = { cow, dog, duck };

  OldMacdonald old_macdonald(3, farm);
  old_macdonald.sing();

  return 0;
}
