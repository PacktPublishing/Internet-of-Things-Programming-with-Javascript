package ror.controlmotorcd;

import android.os.Bundle;
import android.app.Activity;
import android.content.res.ColorStateList;
import android.graphics.Color;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;
import android.widget.TextView;
import at.abraxas.amarino.Amarino;

public class MainActivity extends Activity implements OnSeekBarChangeListener{

	private static final String DEVICE_ADDRESS = "98:D3:31:50:0F:B6";
	
	SeekBar control;
	TextView Mensaje;
	TextView pwm;
	TextView giro;
	Button adelante;
	Button atras;
	Button detener;
	Button Conectar;
	Button Desconectar;
	
	int vel = 127;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		
		pwm = (TextView) findViewById(R.id.txtpwm);
		giro = (TextView) findViewById(R.id.txtgiro);
		Mensaje = (TextView) findViewById(R.id.txtmensaje);
		control = (SeekBar) findViewById(R.id.velocidad);
		adelante = (Button) findViewById(R.id.btnAdelante);
		atras = (Button) findViewById(R.id.btnatras);
		detener = (Button) findViewById(R.id.btndetener);
		Conectar = (Button) findViewById(R.id.btnconectar);
		Desconectar = (Button) findViewById(R.id.btndesconectar);
		
		
		Mensaje.setTextColor(Color.BLUE);
		
		adelante.setEnabled(false);
		atras.setEnabled(false);
		detener.setEnabled(false);
		
		Desconectar.setEnabled(false);
		control.setEnabled(false);
		
		control.setOnSeekBarChangeListener(this);
		
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	
	public void onProgressChanged(SeekBar seekbar, int progress, boolean arg2) {
		// TODO Auto-generated method stub
		
		pwm.setText("Value PWM: "+progress);
		
		vel = control.getProgress();
		Amarino.sendDataToArduino(this, DEVICE_ADDRESS,'v',vel);
		
		Desconectar.setEnabled(false);
		
	}

	@Override
	public void onStartTrackingTouch(SeekBar seekBar) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onStopTrackingTouch(SeekBar seekBar) {
		// TODO Auto-generated method stub
		
	}
	
	public void Izquierda(View view) {

		vel = control.getProgress();
		
		int controlbarra = vel;
		control.setProgress(vel);
		pwm.setText("Value PWM: "+controlbarra);
		
		giro.setTextColor(Color.GREEN);
		adelante.setTextColor(Color.GREEN);
		giro.setText("Motor: Left");
		
		
		control.setEnabled(true);
		Conectar.setEnabled(false);
		detener.setEnabled(true);
		
		atras.setTextColor(Color.BLACK);
		detener.setTextColor(Color.BLACK);
		
		Amarino.sendDataToArduino(this, DEVICE_ADDRESS,'i',vel);
    	}
	
	
	public void Derecha(View view) {
		
		
		vel = control.getProgress();
		
		int controlbarra = vel;
		control.setProgress(vel);
		
		pwm.setText("Value PWM: "+controlbarra);
		giro.setTextColor(Color.BLUE);
		atras.setTextColor(Color.BLUE);
		giro.setText("Motor: Right");
		
		Conectar.setEnabled(false);
		detener.setEnabled(true);
		control.setEnabled(true);
		
		adelante.setTextColor(Color.BLACK);
		detener.setTextColor(Color.BLACK);
		
		Amarino.sendDataToArduino(this, DEVICE_ADDRESS,'d',vel);
    	}
	
	
	public void Detener(View view) {
				
		int vel = 0;
		int controlbarra = 0;
		control.setProgress(vel);
		pwm.setText("Value PWM: "+controlbarra);
		giro.setTextColor(Color.RED);
		detener.setTextColor(Color.RED);
		giro.setText("Motor: Stopped");
		Amarino.sendDataToArduino(this, DEVICE_ADDRESS,'s',vel);
		
		Desconectar.setEnabled(true);
		detener.setEnabled(false);
		control.setEnabled(false);
		
		
		adelante.setTextColor(Color.BLACK);
		atras.setTextColor(Color.BLACK);
		
		
	   	}
	

	public void conectar(View view){
		
		
		control.setProgress(vel);
		
		Amarino.connect(this, DEVICE_ADDRESS);
		
		adelante.setEnabled(true);
		atras.setEnabled(true);
		
		Conectar.setEnabled(false);
								
	}
	
	
	public void desconectar(View view){
		
		int vel=0;
		int controlbarra = 0;
		control.setProgress(vel);
		pwm.setText("Value PWM: "+controlbarra);
		
		giro.setTextColor(Color.BLACK);
		giro.setText("Motor: Stopped");
		
		detener.setTextColor(Color.BLACK);
		
		Amarino.sendDataToArduino(this, DEVICE_ADDRESS,'s',vel);
		Amarino.disconnect(this, DEVICE_ADDRESS);
		

		adelante.setEnabled(false);
		atras.setEnabled(false);
		detener.setEnabled(false);
		
		Conectar.setEnabled(true);
		control.setEnabled(false);
		
		Desconectar.setEnabled(false);
	}
	
}
