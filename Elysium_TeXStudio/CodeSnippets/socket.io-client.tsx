// Step 1: Import the io function from the socket.io-client package
import io from "socket.io-client";

// Step 2: Initialize the socket connection
// If your front-end is served on the same domain as your server, you can use the default initialization:
const socket = io();

// If your front-end is not served from the same domain as your server, pass the server URL to the io function:
const socket = io("https://server-domain.com");

// Step 3: Initiate connection and listen for events
// In this example, we listen for the "file_changed_logs" event and update the logs state accordingly
socket.on("file_changed_logs", (data) => {
  // Update the logs state with the new data
  setLogs((prevLogs) => [data.data, ...prevLogs]);
  // Log the new data to the console for debugging purposes
  console.log(data.data);
});

// Step 4: Cleanup on component unmount
// It's important to clean up the event listeners when the component unmounts to avoid memory leaks
return () => {
  // Remove the "file_changed_logs" event listener
  socket.off("file_changed_logs");
};