$key_path="SOFTWARE\\Microsoft\\Cryptography"
$volume_info=Get-WmiObject Win32_volume
$target_volume_serial="";
$found_c_drive=$false;
for($i=0;$i-lt $volume_info.Length;$i++){
if($volume_info[$i].Name.Equals("C:\")){
$found_c_drive=$true;
$target_volume_serial="{0:X}" -f $volume_info[$i].SerialNumber;
break;
}

}

if($found_c_drive -eq $true){

$machine_GUID=(Get-ItemProperty ("HKLM:{0}" -f $key_path)).MachineGuid;


$PC_hash=$machine_GUID+$target_volume_serial;


$stringAsStream = [System.IO.MemoryStream]::new()
$writer = [System.IO.StreamWriter]::new($stringAsStream)
$writer.write($PC_hash);
$writer.Flush()
$stringAsStream.Position = 0

$round1=(Get-fileHash -Algorithm SHA256 -InputStream $stringAsStream).hash


$round2=($round1+"plikan").toLower();
echo $round2; 

$stringAsStream = [System.IO.MemoryStream]::new()
$writer = [System.IO.StreamWriter]::new($stringAsStream)
$writer.write($round2);
$writer.Flush()
$stringAsStream.Position = 0

$round2=((Get-fileHash -Algorithm SHA256 -InputStream $stringAsStream).hash).toLower()




$stringAsStream = [System.IO.MemoryStream]::new()
$writer = [System.IO.StreamWriter]::new($stringAsStream)
$writer.write($round2);
$writer.Flush()
$stringAsStream.Position = 0

$round3=(Get-fileHash -Algorithm SHA512 -InputStream $stringAsStream).hash.toLower()

$key= "{0}-{1}-{2}-{3}-{4}" -f $round3.Substring(0,5),$round3.Substring(5,5),$round3.Substring(10,5),$round3.Substring(15,5),$round3.Substring(20,5)
echo "Serial :  $key"
}
else{
echo "The challenge explicitly gets the volume serial of the c:\\ , maybe you do not have a local drive assigned as C:\\ , try to change any volume letter to c:\\"
}