// SepCheckAndCopySelfRelativeSD 
 
int __fastcall SepCheckAndCopySelfRelativeSD(int a1, int *a2, _DWORD *a3, _BYTE *a4)
{
  int v5; // r5
  int v9; // r0
  int varg_r0[4]; // [sp+28h] [bp+8h] BYREF

  varg_r0[1] = (int)a2;
  varg_r0[2] = (int)a3;
  varg_r0[3] = (int)a4;
  v5 = 0;
  *a2 = 0;
  *a3 = 0;
  varg_r0[0] = a1;
  *a4 = 0;
  if ( a1 )
  {
    if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
    {
      *a3 = SepSecurityDescriptorStrictLength(a1);
      *a2 = a1;
    }
    else
    {
      v5 = RtlAbsoluteToSelfRelativeSD(varg_r0, 0, a3);
      if ( v5 == -1073741789 )
      {
        v9 = ExAllocatePoolWithTag(1, *a3);
        *a2 = v9;
        if ( v9 )
        {
          v5 = RtlAbsoluteToSelfRelativeSD(varg_r0[0], v9, a3);
          if ( v5 >= 0 )
          {
            *a4 = 1;
          }
          else
          {
            ExFreePoolWithTag(*a2);
            *a2 = 0;
          }
        }
        else
        {
          v5 = -1073741670;
        }
      }
    }
  }
  return v5;
}
