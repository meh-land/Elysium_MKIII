import { BrowserRouter, Route, Link, Routes }
    from "react-router-dom";
// Import the pages
import Page1 from "./Components/page1"
function App() {
    return (
        <div className="App">
            <BrowserRouter>
                <Routes>
                    <Route exact path="/" element={<h1>Home Page</h1>} />
                    <Route exact path="page1" element={<Page1 />} />
                </Routes>
            </BrowserRouter>
        </div>
    );
}
export default App;