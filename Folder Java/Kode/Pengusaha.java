// Pengusaha.java
class Pengusaha extends Person {
    private int id;
    private String namaBisnis;
    private String startUpDate;
    private double pendapatan;

    public Pengusaha() {}

    public Pengusaha(String nama, String alamat, int usia, String gender, int id, String namaBisnis, String startUpDate, double pendapatan) {
        super(nama, alamat, usia, gender);
        this.id = id;
        this.namaBisnis = namaBisnis;
        this.startUpDate = startUpDate;
        this.pendapatan = pendapatan;
    }

    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getNamaBisnis() { return namaBisnis; }
    public void setNamaBisnis(String namaBisnis) { this.namaBisnis = namaBisnis; }

    public String getStartUpDate() { return startUpDate; }
    public void setStartUpDate(String startUpDate) { this.startUpDate = startUpDate; }

    public double getPendapatan() { return pendapatan; }
    public void setPendapatan(double pendapatan) { this.pendapatan = pendapatan; }

    public double hitungProfit() { return pendapatan * 0.3; }
}