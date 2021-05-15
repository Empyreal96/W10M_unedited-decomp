// PopTimestampTargetProcessor 
 
int __fastcall PopTimestampTargetProcessor(int a1, int a2, _QWORD *a3, int a4)
{
  __int64 v6; // r0

  LODWORD(v6) = ReadTimeStampCounter();
  *a3 = v6;
  return KeSetEvent(a4, 0, 0);
}
