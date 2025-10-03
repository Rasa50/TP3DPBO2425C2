// Person.java
class Person {
    private String nama;
    private String alamat;
    private int usia;
    private String gender;

    public Person() {}

    public Person(String nama, String alamat, int usia, String gender) {
        this.nama = nama;
        this.alamat = alamat;
        this.usia = usia;
        this.gender = gender;
    }

    public String getNama() { return nama; }
    public void setNama(String nama) { this.nama = nama; }

    public String getAlamat() { return alamat; }
    public void setAlamat(String alamat) { this.alamat = alamat; }

    public int getUsia() { return usia; }
    public void setUsia(int usia) { this.usia = usia; }

    public String getGender() { return gender; }
    public void setGender(String gender) { this.gender = gender; }
}