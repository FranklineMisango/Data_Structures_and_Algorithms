import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
class PercolationTest {
    private Percolation sy = new Percolation(4);

    @Test
    void open() {
        sy.open(1, 1);
        assertEquals(sy.numberOfOpenSites(), 1);

        sy.open(1,2);
        assertEquals(sy.numberOfOpenSites(), 2);
    }

    @Test
    void isOpen() {
        sy.open(4, 2);
        assertTrue(sy.isOpen(4,2));
        assertFalse(sy.isOpen(1,3));
    }

    @Test
    void isFull() {
        sy.open(1,3);
        assertTrue(sy.isFull(1,3));
        assertFalse(sy.isFull(1,2));

        sy.open(3,3);
        assertFalse(sy.isFull(3,3));

        sy.open(2,3);
        assertTrue(sy.isFull(2,3));
        assertTrue(sy.isFull(3,3));
        assertFalse(sy.isFull(4,3));

        assertFalse(sy.isFull(4,1));
        assertFalse(sy.isFull(4,4));


    }

    @Test
    void numberOfOpenSites() {
        sy.open(1,1);
        assertEquals(sy.numberOfOpenSites(), 1);

        sy.open(4,4);
        assertEquals(sy.numberOfOpenSites(), 2);

        sy.open(4,1);
        assertEquals(sy.numberOfOpenSites(), 3);
    }

    @Test
    void percolates() {
        assertFalse(sy.percolates());

        sy.open(1,3);
        sy.open(2,4);

        assertFalse(sy.percolates());

        sy.open(2,3);
        sy.open(3,3);

        assertFalse(sy.percolates());

        sy.open(4,1);
        sy.open(4,2);

        assertFalse(sy.percolates());

        sy.open(4,3);

        assertTrue(sy.percolates());
    }

}