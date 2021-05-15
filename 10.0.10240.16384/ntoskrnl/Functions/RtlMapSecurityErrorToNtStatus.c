// RtlMapSecurityErrorToNtStatus 
 
int __fastcall RtlMapSecurityErrorToNtStatus(int result)
{
  if ( result > -2146893034 )
  {
    switch ( result )
    {
      case -2146893020:
        result = -1073741517;
        break;
      case -2146893007:
LABEL_6:
        result = -1073741637;
        break;
      case -2146892963:
LABEL_19:
        result = -1073741811;
        break;
    }
  }
  else if ( result == -2146893034 )
  {
LABEL_9:
    result = -1073741570;
  }
  else
  {
    switch ( result )
    {
      case -2146893056:
        result = -1073741670;
        break;
      case -2146893055:
        result = -1073741816;
        break;
      case -2146893054:
      case -2146893046:
        goto LABEL_6;
      case -2146893053:
        result = -1073741634;
        break;
      case -2146893052:
        result = -1073741595;
        break;
      case -2146893051:
      case -2146893049:
        goto LABEL_9;
      case -2146893050:
        result = -1073741727;
        break;
      case -2146893048:
      case -2146893047:
        goto LABEL_19;
      case -2146893045:
        result = -1073741555;
        break;
      case -2146893044:
        result = -1073741715;
        break;
      case -2146893043:
      case -2146893042:
        result = -1073741729;
        break;
      case -2146893041:
      case -2146893040:
        result = -1073741790;
        break;
      case -2146893039:
        result = -1073741730;
        break;
      default:
        return result;
    }
  }
  return result;
}
