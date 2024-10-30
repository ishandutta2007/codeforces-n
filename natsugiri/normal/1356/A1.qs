namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            unitary(q);
            let m = M(q);
            Reset(q);
            if (m == Zero) {
                return 0;   
			} else {
                return 1;     
			}
		}
    }
}