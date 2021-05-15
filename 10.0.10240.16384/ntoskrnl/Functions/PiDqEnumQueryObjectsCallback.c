// PiDqEnumQueryObjectsCallback 
 
int __fastcall PiDqEnumQueryObjectsCallback(int a1, int a2, _BYTE *a3)
{
  *a3 = 0;
  return PiDqQueryEnumObject(a2, a1, (int)a3, a2);
}
