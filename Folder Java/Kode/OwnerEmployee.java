// OwnerEmployee.java
class OwnerEmployee extends Employee {
    private Pengusaha pengusahaData;
    private int idOE;
    private String persentaseKepemilikan;
    private String statusManajemen;

    public OwnerEmployee() {
        super();
        this.pengusahaData = new Pengusaha();
    }
    
    public OwnerEmployee(String nama, String alamat, int usia, String gender,
                         int idE, String posisi, String email, double gaji,
                         int idP, String namaBisnis, String startUpDate, double pendapatan,
                         int idOE, String persentaseKepemilikan, String statusManajemen) {
        super(nama, alamat, usia, gender, idE, posisi, email, gaji, null);
        this.pengusahaData = new Pengusaha(nama, alamat, usia, gender, idP, namaBisnis, startUpDate, pendapatan);
        this.idOE = idOE;
        this.persentaseKepemilikan = persentaseKepemilikan;
        this.statusManajemen = statusManajemen;
    }

    public int getPengusahaId() { return pengusahaData.getId(); }
    public void setPengusahaId(int id) { this.pengusahaData.setId(id); }
    public String getNamaBisnis() { return pengusahaData.getNamaBisnis(); }
    public void setNamaBisnis(String namaBisnis) { this.pengusahaData.setNamaBisnis(namaBisnis); }
    public String getStartUpDate() { return pengusahaData.getStartUpDate(); }
    public void setStartUpDate(String startUpDate) { this.pengusahaData.setStartUpDate(startUpDate); }
    public double getPendapatan() { return pengusahaData.getPendapatan(); }
    public void setPendapatan(double pendapatan) { this.pengusahaData.setPendapatan(pendapatan); }
    public double hitungProfit() { return pengusahaData.hitungProfit(); }

    public int getIdOE() { return idOE; }
    public void setIdOE(int idOE) { this.idOE = idOE; }

    public String getPersentaseKepemilikan() { return persentaseKepemilikan; }
    public void setPersentaseKepemilikan(String persentaseKepemilikan) { this.persentaseKepemilikan = persentaseKepemilikan; }

    public String getStatusManajemen() { return statusManajemen; }
    public void setStatusManajemen(String statusManajemen) { this.statusManajemen = statusManajemen; }

    public double hitungTotalKompensasi() {
        return hitungGajiTahunan() + (hitungProfit() * 0.5);
    }
}