<?php 
function tof ($n,$src,$dest,$aux) {
    if ($n == 1){
        echo 'Move disk 1 from '.$src." to ". $dest."\n";
        return 0;
    }
    tof($n-1, $src,$aux,$dest);
    echo 'Move disk '. $n. ' from '.$src." to ". $dest."\n";

    tof($n-1, $aux,$dest,$src);
}

$n = (int)readline("Enter n : ");
tof($n,'Source','Destination','Auxiliary')

?>