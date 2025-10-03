// GorOlahraga.java
class GorOlahraga extends TempatUsaha {
    private String jenisOlahraga;
    private String fasilitas;
    private String skala;
    private double hargaSewa;

    public GorOlahraga() {}
    
    public GorOlahraga(String namaTempat, String noIzin, String kategoriUsaha, String lokasi, String deskripsi,
                       String jenisOlahraga, String fasilitas, String skala, double hargaSewa) {
        super(namaTempat, noIzin, kategoriUsaha, lokasi, deskripsi);
        this.jenisOlahraga = jenisOlahraga;
        this.fasilitas = fasilitas;
        this.skala = skala;
        this.hargaSewa = hargaSewa;
    }
}