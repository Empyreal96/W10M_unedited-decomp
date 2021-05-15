// RtlIsServicePackVersionInstalled 
 
BOOL __fastcall RtlIsServicePackVersionInstalled(int a1)
{
  return (a1 & 0xFFFF0000) == 167772160 && (a1 & 0xFF00) == 0;
}
