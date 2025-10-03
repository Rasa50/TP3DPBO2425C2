// Aula.java
class Aula extends TempatUsaha {
    private double luas;
    private String kapasitas;
    private String fasilitas;
    private double hargaSewa;
    private String tipe;

    public Aula() {}
    
    public Aula(String namaTempat, String noIzin, String kategoriUsaha, String lokasi, String deskripsi,
                double luas, String kapasitas, String fasilitas, double hargaSewa, String tipe) {
        super(namaTempat, noIzin, kategoriUsaha, lokasi, deskripsi);
        this.luas = luas;
        this.kapasitas = kapasitas;
        this.fasilitas = fasilitas;
        this.hargaSewa = hargaSewa;
        this.tipe = tipe;
    }
}