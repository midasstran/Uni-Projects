package ThucPham;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.text.DecimalFormat;

public class HangThucPham {
	private int id;
	 private String maHang;
	 private String tenHang;
	 private LocalDate ngaySanXuat;
	 private LocalDate ngayHetHan;
	 private float gia;
	 private static int demSoLuong=0;
	
	 

	public int getId() {
		return id;
	}



	public void setId(int id) {
		this.id = id;
	}



	public String getMaHang() {
		return maHang;
	}



	public void setMaHang(String maHang) {
		if (maHang==null || maHang.trim().isEmpty()) {
			throw new IllegalArgumentException("Ma hang khong duoc de trong!");
		}
		this.maHang = maHang;
	}



	public String getTenHang() {
		return tenHang;
	}



	public void setTenHang(String tenHang) {
		if (tenHang==null || tenHang.trim().isEmpty()) {
			throw new IllegalArgumentException("Ten hang khong duoc de trong!");
		}
		this.tenHang = tenHang;
	}



	public LocalDate getNgaySanXuat() {
		return ngaySanXuat;
	}



	public void setNgaySanXuat(LocalDate ngaySanXuat) {
		this.ngaySanXuat = ngaySanXuat;
	}



	public LocalDate getNgayHetHan() {
		return ngayHetHan;
	}



	public void setNgayHetHan(LocalDate ngayHetHan) {
		this.ngayHetHan = ngayHetHan;
	}



	public float getGia() {
		return gia;
	}



	public void setGia(float gia) {
		if (gia<0) {
			throw new IllegalArgumentException("Gia tien khong duoc am!");
		}
		this.gia = gia;
	}

	
	public HangThucPham() {
		this.id = ++demSoLuong;
		this.maHang = "Chua co";
		this.tenHang = "xxx";
		this.ngaySanXuat = LocalDate.now();
		this.ngayHetHan = LocalDate.now().plusDays(7);
		this.gia = 1.0f;
	}

	public HangThucPham(String maHang, String tenHang, LocalDate ngaySanXuat, LocalDate ngayHetHan, float gia) {
		this.id = ++demSoLuong;
		setMaHang(maHang);
		setTenHang(tenHang);
		this.ngaySanXuat = ngaySanXuat;
		this.ngayHetHan = ngayHetHan;
//		this.gia = gia;
		setGia(gia);
	}
	
	public boolean hethan() {
		if(ngayHetHan==null) return false;
		return ngayHetHan.isBefore(LocalDate.now());
	}
	
//	public boolean condate() {
//		if (this.ngaySanXuat==null || this.ngayHetHan==null) return false;
//		LocalDate homnay=LocalDate.now();
//		return !homnay.isBefore(this.ngaySanXuat) && !homnay.isAfter(this.ngayHetHan);
//	}
//	
	
	@Override
	public String toString() {
		DecimalFormat df = new DecimalFormat("#,##0.00VND");
		DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		String strNSX=(ngaySanXuat!=null) ? dtf.format(ngaySanXuat):"N/A";
		String strNHH=(ngayHetHan!=null) ? dtf.format(ngayHetHan):"N/A";
		String ghiChu=hethan() ? "Hang het han!":"";
		return String.format("%-5d %-10s %-20s %-18s %-15s %-15s %s",id,maHang,tenHang,df.format(gia),strNSX,strNHH,ghiChu);
	}



	public static void main(String[] args) {

	}

}
