// import java.io.*;
import java.util.*;

public class Enclosure {
    private ArrayList<Animal> animals;

    public Enclosure() {
        // Inisialisasi ArrayList animals kosong
        animals = new ArrayList<Animal>();
    } 

    public int getAnimalCount() {
        // Mengembalikan jumlah hewan dalam this.animals
        return animals.size();
    }

    public void addAnimal(Animal animal) {
        // menambahkan seekor hewan ke dalam this.animals
        animals.add(animal);
    }

    public Animal getAnimalAt(int i) {
        // mengembalikan hewan dalam this.animals pada index i (tidak mengubah this.animals)
        return animals.get(i);
    }

    public void removeAnimalAt(int i) {
        // menghapus hewan pada this.animals pada index i
        animals.remove(i);
    }

    public boolean isEmpty() {
        // mengembalikan boolean yang menyatakan apakah this.animals kosong atau tidak

        // return !(animals.size() == 0);
        return animals.isEmpty();
    }

    public void describe() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong menuliskan output serupa dengan output berikut:
        // Kandang berisi 2 ekor hewan:
        // 1. po, spesies Pandamus Maximus, umur 5 tahun
        // 2. po2, spesies Pandamus Maximus, umur 5 tahun
        if (animals.isEmpty()) {
            System.out.println("Kandang ini kosong...");
        }
        else {
            System.out.printf("Kandang berisi %d ekor hewan:\n", getAnimalCount());
            for (int i = 0; i < getAnimalCount(); i++) {
                System.out.printf("%d. %s, spesies %s, umur %d tahun\n", i + 1, animals.get(i).getName(), animals.get(i).getSpecies(), animals.get(i).getAge());
            }
        }
    }

    public void feed() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong maka akan memanggil method eat pada tiap animal dalam this.animals
        if (animals.isEmpty()) {
            System.out.println("Kandang ini kosong...");
        }
        else {
            animals.stream().forEach(animal -> animal.eat());
        }
    }

    public boolean safeForPetting() {
        // mengembalikan true apabila semua hewan dalam this.animals bersifat friendly
        boolean flag = true;
        for (int i = 0; i < getAnimalCount(); i++) {
            if (!animals.get(i).isFriendly()) {
                flag = false;
                break;
            }
        }
        return flag;
    }
}