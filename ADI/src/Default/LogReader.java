package Default;

import java.util.HashMap;
import java.util.Map;

public class LogReader {

	@SuppressWarnings("static-access")
	public static void main(String[] args) throws InterruptedException {
		@SuppressWarnings({ "unchecked", "rawtypes" })
		Map<String , Integer> m = new HashMap();
		
	/*	UpdateData u = new UpdateData(m);
		u.run();
		UpdateData u1 = new UpdateData(m);
		u1.run();
		UpdateData u2 = new UpdateData(m);
		u2.run();
		UpdateData u3 = new UpdateData(m);
		u3.run();
		UpdateData u4 = new UpdateData(m);
		u4.run();
		
		System.out.println(m.get("a"));*/
		
		/*Thread t1 = new Thread(new UpdateData(m));
		Thread t2 = new Thread(new UpdateData(m));
		Thread t3 = new Thread(new UpdateData(m));
		Thread t4 = new Thread(new UpdateData(m));
		Thread t5 = new Thread(new UpdateData(m));
		Thread t6 = new Thread(new UpdateData(m));
		Thread t7 = new Thread(new UpdateData(m));
		
		t1.start();
		t2.start();
		t3.start();
		t4.start();
		t5.start();
		t6.start();
		t7.start();
		
		t1.join();
		t2.join();
		
		System.out.println(m.get("a"));
		Thread.currentThread().sleep(3000);*/
		
		Thread t = null;
		for(int i=0;i<1000;i++) {
			t = new Thread(new UpdateData(m));
			t.start();
		}
		
		Thread.currentThread().sleep(3000);
		System.out.println(m.get("a"));
		
	}

}
