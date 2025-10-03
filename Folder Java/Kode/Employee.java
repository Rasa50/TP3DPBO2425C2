// Employee.java
class Employee extends Person {
    private int id;
    private String posisi;
    private String email;
    private double gaji;
    private TempatUsaha tempatKerja;

    public Employee() {}

    public Employee(String nama, String alamat, int usia, String gender, int id, String posisi, String email, double gaji, TempatUsaha tempatKerja) {
        super(nama, alamat, usia, gender);
        this.id = id;
        this.posisi = posisi;
        this.email = email;
        this.gaji = gaji;
        this.tempatKerja = tempatKerja;
    }

    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getPosisi() { return posisi; }
    public void setPosisi(String posisi) { this.posisi = posisi; }

    public String getEmail() { return email; }
    public void setEmail(String email) { this.email = email; }

    public double getGaji() { return gaji; }
    public void setGaji(double gaji) { this.gaji = gaji; }

    public double hitungGajiTahunan() { return gaji * 12; }

    public TempatUsaha getTempatKerja() { return tempatKerja; }
    public void setTempatKerja(TempatUsaha tempatKerja) { this.tempatKerja = tempatKerja; }
}