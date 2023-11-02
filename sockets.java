import java.io.*;
import java.net.*;

public class sockets {
    public static void main(String[] args) {
        ServerSocket ss = null;
        try {
            // Create a server socket on port 6666
            ss = new ServerSocket(6666);
            
            // Wait for a client to establish a connection
            Socket s = ss.accept();
            
            // Create a DataInputStream to receive data from the client
            DataInputStream dis = new DataInputStream(s.getInputStream());
            
            // Read the message sent by the client
            String str = dis.readUTF();
            
            // Print the received message
            System.out.println("message = " + str);
            
            // Close the server socket
            ss.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
