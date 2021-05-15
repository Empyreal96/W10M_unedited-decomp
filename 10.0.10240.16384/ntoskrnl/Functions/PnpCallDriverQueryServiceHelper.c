// PnpCallDriverQueryServiceHelper 
 
int __fastcall PnpCallDriverQueryServiceHelper(int *a1, int *a2, int a3, int a4, int a5, char a6, int a7, int a8)
{
  int result; // r0
  unsigned int v11; // r5
  unsigned __int16 *v12; // r4
  unsigned int v13; // r6
  unsigned int v14; // [sp+10h] [bp-28h] BYREF
  int v15[9]; // [sp+14h] [bp-24h] BYREF

  v14 = *a2;
  if ( a6 )
    result = CmGetInstallerClassRegProp(PiPnpRtlCtx, a4, a5, a3, v15, *a1, &v14);
  else
    result = CmGetDeviceRegProp(PiPnpRtlCtx, a4, a5, a3, (int)v15, *a1, (int)&v14);
  if ( result == -1073741789 )
    return sub_7CAF7C();
  if ( result >= 0 )
  {
    if ( v15[0] == 7 )
    {
      if ( (unsigned int)*a2 < 2 || (v11 = v14, v14 < 2) )
      {
        result = -1073741823;
      }
      else
      {
        v12 = (unsigned __int16 *)*a1;
        if ( *(_WORD *)*a1 )
        {
          while ( 1 )
          {
            v13 = wcslen(v12) + 1;
            if ( v11 < 2 * v13 )
              break;
            v14 = v11 - 2 * v13;
            result = PipCallDriverAddDeviceQueryRoutine(1, v12, 2 * v13, a8, a7);
            if ( result >= 0 )
            {
              v11 = v14;
              if ( v14 >= 2 )
              {
                v12 += v13;
                if ( *v12 )
                  continue;
              }
            }
            return result;
          }
          result = 0;
        }
      }
    }
    else
    {
      result = PipCallDriverAddDeviceQueryRoutine(v15[0], *a1, v14, a8, a7);
    }
  }
  return result;
}
