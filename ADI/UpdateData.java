import java.util.HashMap;
import java.util.Map;

public class UpdateData implements Runnable {
	
	@SuppressWarnings({ "unchecked", "rawtypes" })
	private Map<String , Integer> m = new HashMap();

	public UpdateData(Map<String,Integer> m){
		this.m = m;
	}
	

	@Override
	public void run() {
		synchronized (m) {
			if(m.get("a") == null) {
				m.put("a", 1);
			}else {
				@SuppressWarnings("unused")
				int t = m.get("a");
				m.put("a",1);
			}
		}
	}

}
