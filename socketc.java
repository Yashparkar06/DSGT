import java.io.*;
import java.net.*;

public class socketc {
    public static void main(String[] args) {
        try {
            // Create a socket and connect to the server on localhost and port 6666
            Socket s = new Socket("localhost", 6666);

            // Create a DataOutputStream to send data to the server
            DataOutputStream dout = new DataOutputStream(s.getOutputStream());

            // Write a UTF-encoded string to the server
            dout.writeUTF("Hello Server");
            
            // Flush the data to ensure it's sent immediately
            dout.flush();
            
            // Close the output stream and the socket
            dout.close();
            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
