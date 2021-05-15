// SiGetBiosSystemDisk 
 
int __fastcall SiGetBiosSystemDisk(int *a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r4
  int v7; // r6
  int v8; // r0
  int v10; // [sp+0h] [bp-20h] BYREF
  int v11; // [sp+4h] [bp-1Ch]
  int v12; // [sp+8h] [bp-18h] BYREF
  int v13; // [sp+Ch] [bp-14h]

  v11 = a2;
  v12 = a3;
  v13 = a4;
  v10 = 0;
  v5 = 0;
  if ( !SiIsWinPeHardDiskZeroUfdBoot()
    || (v6 = SiOpenArcNameObject(L"\\ArcName\\multi(0)disk(0)rdisk(1)", &v10), v6 == -1073740718) )
  {
    v6 = SiOpenArcNameObject(L"\\ArcName\\multi(0)disk(0)rdisk(0)", &v10);
  }
  v7 = v10;
  if ( v6 >= 0 )
  {
    v11 = 0;
    RtlInitUnicodeString((unsigned int)&v12, 0);
    v8 = ZwQuerySymbolicLinkObject();
    v6 = v8;
    if ( v8 == -1073741789 )
    {
      v5 = ExAllocatePoolWithTag(1, v11 + 2, 1263556947);
      if ( v5 )
      {
        HIWORD(v12) = v11;
        v13 = v5;
        v6 = ZwQuerySymbolicLinkObject();
        if ( v6 >= 0 )
        {
          *(_WORD *)(v5 + 2 * ((unsigned __int16)v12 >> 1)) = 0;
          *a1 = v5;
        }
      }
      else
      {
        v6 = -1073741670;
      }
    }
    else if ( v8 >= 0 )
    {
      v6 = -1073741823;
    }
  }
  if ( v7 )
    ZwClose();
  if ( v6 < 0 && v5 )
    ExFreePoolWithTag(v5);
  return v6;
}
