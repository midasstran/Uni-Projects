package ThucPham;
import java.time.LocalDate;

public class Main {
	public static void main(String args[]) {
		 HangThucPham h1 = new HangThucPham(
		            "001",
		            "Gao",
		            LocalDate.of(2018, 10, 7),
		            LocalDate.of(2018, 10, 7),
		            100000
		        );

		        HangThucPham h2 = new HangThucPham(
		            "002",
		            "Mi",
		            LocalDate.of(2018, 1, 3),
		            LocalDate.of(2018, 9, 1),
		            5000
		        );

		        HangThucPham h3 = new HangThucPham(
		            "003",
		            "Nuoc",
		            LocalDate.of(2017, 3, 1),
		            LocalDate.of(2018, 3, 1),
		            10000
		        );
		        System.out.printf(
		                "%-10s %-10s %-18s %-15s %-15s %-15s%n",
		                "Mã_Hàng",
		                "Tên_Hàng",
		                "Đơn_Giá",
		                "Ngày_Sản_Xuất",
		                "Ngày_Hết_Hạn",
		                "Ghi_Chú"
		            );

		        
		        System.out.println(
		                "--------------------------------------------------------------------------"
		            );
		        System.out.println(h1);
		        System.out.println(h2);
		        System.out.println(h3);
		        try {
		            HangThucPham h4 = new HangThucPham(
		                "",
		                "Sua",
		                LocalDate.of(2020, 1, 1),
		                LocalDate.of(2020, 2, 1),
		                15000
		            );
		        } catch (IllegalArgumentException e) {
		            System.out.println("Loi: " + e.getMessage());
		        }
	}
}
// kkkkkk