// IopCaptureObjectName 
 
int __fastcall IopCaptureObjectName(int a1)
{
  int v1; // r4
  int v2; // r0
  int v4; // [sp-4h] [bp-210h] BYREF
  unsigned __int16 v5; // [sp+4h] [bp-208h] BYREF
  int v6; // [sp+8h] [bp-204h]

  v1 = 0;
  if ( ObQueryNameString(a1, &v5, 512, &v4) >= 0 )
  {
    if ( v6 )
    {
      v2 = ExAllocatePoolWithTag(512, v5 + 2, 1920421956);
      v1 = v2;
      if ( v2 )
      {
        memmove(v2, v6, v5);
        *(_WORD *)(v1 + 2 * (v5 >> 1)) = 0;
      }
    }
  }
  return v1;
}
