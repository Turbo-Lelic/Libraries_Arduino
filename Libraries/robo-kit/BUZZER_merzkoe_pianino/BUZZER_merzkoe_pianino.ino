	#define BUZZER_PIN    13 // ��� � �������� (����. �buzzer�)
	    #define FIRST_KEY_PIN 7  // ������ ��� � �������� (����. �key�)
	    #define KEY_COUNT     3  // ����� ���������� ������
	 
	    void setup()
	    {
	      pinMode(BUZZER_PIN, OUTPUT);
	    }
	 
	    void loop()
	    {
	      // � ����� ����� �� ���� ������� ������ �� 0-�� �� 2-�
	      for (int i = 0; i < KEY_COUNT; ++i) {
	        // �� ������ ������ ������ ��������� ����� � ����
	        int keyPin = i + FIRST_KEY_PIN;
	 
	        // ��������� �������� � ������. �������� ����� 2 ��������:
	        //  * ������� ������, 5 �����, ������ � ������ ��������
	        //  * ������ ������, �����, ���� � ������ ������
	        boolean keyUp = digitalRead(keyPin);
	 
	        // ��������� ������� ����� �� ������ ��������. ���� �!�
	        // ����� ������� ���������� �������� ���������, �.�. ���.
	        if (!keyUp) {
	          // ������������ ������ ���� � ������ � ����������� ��
	          // �������, ������� ������������� �� ������ ����� �����.
	          // �� ������� �������� 3500, 4000 ��� 4500
	          int frequency = 3500 + i * 500;
	 
	          // ���������� ������� ������ � ������ �������� � �������
	          // 20 �����������. ���� ������� ��������� �������, �������
	          // ����� �������� ��� ��������� ������� loop, � �� �������
	          // ����������� ����
	          tone(BUZZER_PIN, frequency, 20);
	        }
	      }
    }
