// TempatUsaha.java
class TempatUsaha {
    private String namaTempat;
    private String noIzin;
    private String kategoriUsaha;
    private String lokasi;
    private String deskripsi;

    public TempatUsaha() {}

    public TempatUsaha(String namaTempat, String noIzin, String kategoriUsaha, String lokasi, String deskripsi) {
        this.namaTempat = namaTempat;
        this.noIzin = noIzin;
        this.kategoriUsaha = kategoriUsaha;
        this.lokasi = lokasi;
        this.deskripsi = deskripsi;
    }

    public String getNamaTempat() { return namaTempat; }
    public void setNamaTempat(String namaTempat) { this.namaTempat = namaTempat; }

    public String getNoIzin() { return noIzin; }
    public void setNoIzin(String noIzin) { this.noIzin = noIzin; }

    public String getKategoriUsaha() { return kategoriUsaha; }
    public void setKategoriUsaha(String kategoriUsaha) { this.kategoriUsaha = kategoriUsaha; }

    public String getLokasi() { return lokasi; }
    public void setLokasi(String lokasi) { this.lokasi = lokasi; }

    public String getDeskripsi() { return deskripsi; }
    public void setDeskripsi(String deskripsi) { this.deskripsi = deskripsi; }
}