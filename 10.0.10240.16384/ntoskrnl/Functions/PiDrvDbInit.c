// PiDrvDbInit 
 
int __fastcall PiDrvDbInit(int a1)
{
  int result; // r0
  __int16 **v3; // r6
  int v4; // r5
  __int16 *v5; // r1
  __int16 *v6; // t1
  int *j; // r5
  int *i; // r4

  result = 0;
  if ( a1 )
  {
    if ( a1 == 2 )
    {
      for ( i = (int *)PiDrvDbNodeList; i != &PiDrvDbNodeList; i = (int *)*i )
      {
        if ( (i[8] & 2) == 0 )
        {
          result = DrvDbSuspendDatabase(PiDrvDbCtx, i[3], 0);
          if ( result < 0 )
            break;
        }
      }
    }
  }
  else
  {
    PiDrvDbNodeList = (int)&PiDrvDbNodeList;
    dword_62F984 = (int)&PiDrvDbNodeList;
    result = DrvDbOpenContext(PiPnpRtlCtx);
    if ( result >= 0 )
    {
      v3 = &PiDrvDbNodeDescriptors;
      v4 = 0;
      while ( 1 )
      {
        v5 = v3[1];
        v6 = *v3;
        v3 += 2;
        result = PiDrvDbRegisterNode(v6, v5);
        if ( result < 0 )
          break;
        if ( (unsigned int)++v4 >= 2 )
        {
          for ( j = (int *)PiDrvDbNodeList; j != &PiDrvDbNodeList; j = (int *)*j )
          {
            if ( (j[8] & 2) == 0 )
            {
              result = DrvDbSuspendDatabase(PiDrvDbCtx, j[3], 1);
              if ( result < 0 )
                break;
            }
          }
          return result;
        }
      }
    }
  }
  return result;
}
