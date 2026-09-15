package Tuan3Bai8;

import java.util.Scanner;

public class ListCD {

    private CD[] cdr;    
    private int count;    

    public ListCD(int n) {
        this.cdr = new CD[n]; 
        this.count = 0;
    }


    public int getCount() {
        return count;
    }

    public void tangKT() {
        if (cdr.length == count) {                     
            CD[] tam = new CD[cdr.length * 2];     
            System.arraycopy(cdr, 0, tam, 0, count); 
            cdr = tam;                                  
        }
    }
    public boolean themCD(CD crom) {
        for (int i = 0; i < count; i++) {
            if (cdr[i].getMaCD().equalsIgnoreCase(crom.getMaCD())) {
                return false;  
            }
        }
        tangKT();
        cdr[count] = crom;
        count++;
        return true;
    }
    public boolean xoa(String maXoa) {
    	for (int i =0;i<count;i++) {
    		if (cdr[i].getMaCD().equalsIgnoreCase(maXoa)) {
    			for (int j=i;j<count-1;j++) {
    				cdr[j]=cdr[j+1];
    			}
    			cdr[count-1]=null;
    			count--;
    			return true;
    		}
    	}
    	return false;
    }
    public boolean capnhatCD(String MaCD,float gia) {
    	for (int i=0;i<count;i++) {
    		if (cdr[i].getMaCD().equalsIgnoreCase(MaCD)) {
    			cdr[i].setGia(gia);
    			return true;
    		}
    	}
    	return false;
    }
    public void inDs() {
    	CD.tieuDe();
    	for (int i=0;i<count;i++) {
    		System.out.println(cdr[i]);
    	}
    }
    
    public float tongThanhTien() {
    	float tong=0;
    	for (int i=0;i<count;i++) {
    		tong+=cdr[i].getGia()*cdr[i].getSoBaiHat();
    	}
    	return tong;
    }
    public void nhapCD(Scanner sc) {
    	try {
    		System.out.println("Nhap ma CD: ");
    		String maCD=sc.nextLine();

            System.out.print("Nhap tua CD: ");
            String tuaCD = sc.nextLine();

            System.out.print("Nhap ten ca sy: ");
            String caSy = sc.nextLine();

            System.out.print("Nhap so bai hat: ");
            int soBai = Integer.parseInt(sc.nextLine());

            System.out.print("Nhap don gia: ");
            float gia = Float.parseFloat(sc.nextLine());
            CD cd = new CD(tuaCD,caSy,soBai,gia,maCD);
            if (themCD(cd)) {
                System.out.println("=> Them CD thanh cong!");
            } else {
                System.out.println("=> Ma CD da ton tai, them that bai!");
            }
    	} catch (Exception e) {
    		System.out.println("=>Loi nhap lieu: "+e.getMessage());
    	}
    }
    public void xoaCD(Scanner sc) {
        System.out.print("Nhap ma CD can xoa: ");
        String maXoa = sc.nextLine();
        if (xoa(maXoa)) {
            System.out.println("=> Xoa thanh cong!");
        } else {
            System.out.println("=> Khong tim thay ma CD: " + maXoa);
        }
    }

    public void capNhatGiaCD(Scanner sc) {
        System.out.print("Nhap ma CD can cap nhat: ");
        String maCD = sc.nextLine();
        try {
            System.out.print("Nhap gia moi: ");
            float gia = Float.parseFloat(sc.nextLine());
            if (capnhatCD(maCD, gia)) {
                System.out.println("=> Cap nhat thanh cong!");
            } else {
                System.out.println("=> Khong tim thay ma CD: " + maCD);
            }
        } catch (NumberFormatException e) {
            System.out.println("=> Gia khong hop le!");
        }
    }
}
