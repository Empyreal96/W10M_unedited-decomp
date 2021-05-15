// WheaGetErrorSource 
 
int __fastcall WheaGetErrorSource(int a1)
{
  int v1; // r0
  int result; // r0

  v1 = WheapGetErrorSource(&WheapErrorSourceTable, a1);
  if ( v1 )
    result = v1 + 73;
  else
    result = 0;
  return result;
}
