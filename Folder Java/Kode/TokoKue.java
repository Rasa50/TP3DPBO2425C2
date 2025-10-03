// TokoKue.java
class TokoKue extends TempatUsaha {
    private String namaProduk;
    private String jenis;
    private int stok;

    public TokoKue() {}
    
    public TokoKue(String namaTempat, String noIzin, String kategoriUsaha, String lokasi, String deskripsi,
                   String namaProduk, String jenis, int stok) {
        super(namaTempat, noIzin, kategoriUsaha, lokasi, deskripsi);
        this.namaProduk = namaProduk;
        this.jenis = jenis;
        this.stok = stok;
    }
}