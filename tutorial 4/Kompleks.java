class Kompleks{
    private static int n_kompleks = 0;
    private int real; 
    private int imaginer;

    public Kompleks(){
        real = 0;
        imaginer = 0;
        n_kompleks++;
    }

    public Kompleks(int real, int imaginer){
        this.real = real;
        this.imaginer = imaginer;
        n_kompleks++;
    }

    public int getReal(){
        return real;
    }
    public int getImaginer(){
        return imaginer;
    }
    
    public void setReal(int a){
        real = a;
    }

    public void setImaginer(int a){
        imaginer = a;
    }

    public Kompleks plus(Kompleks b){
        return new Kompleks(real + b.getReal(), imaginer + b.getImaginer());
    }

    public Kompleks minus(Kompleks b){
        return new Kompleks(real - b.getReal(), imaginer - b.getImaginer());
    }

    public Kompleks multiply(Kompleks b){
        return new Kompleks(real * b.getReal() - imaginer * b.getImaginer(), imaginer * b.getReal() + real * b.getImaginer());
    }

    public Kompleks multiply(int n){
        return new Kompleks(real * n, imaginer * n);
    }

    public void print() {
        if (real != 0) {
            System.out.print(real);
        }
    
        if (imaginer > 0 && real != 0) {
            System.out.print("+");
        }
    
        if (imaginer != 0) {
            System.out.print(imaginer + "i");
        }
    
        if (real == 0 && imaginer == 0) {
            System.out.print("0");
        }
    
        System.out.println();
    }

    public static int countKompleksInstance(){
        return n_kompleks;
    }
}
