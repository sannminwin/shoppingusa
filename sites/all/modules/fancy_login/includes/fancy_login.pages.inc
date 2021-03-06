<?php

/**
 * Callback function for admin/config/people/fancy_login
 * Allows the user to set various CSS settings related to the display of the popup window
 *
 * @see fancy_login_settings_validate()
 */
function fancy_login_settings($form, &$form_state)
{
	form_load_include($form_state, 'inc', 'fancy_login', 'includes/fancy_login.pages');
	$form['display'] = array
	(
		'#type' => 'fieldset',
		'#title' => t('Display'),
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
	);
	$form['display']['explanation'] = array
	(
		'#value' => '<p>' . t('All settings on this page must be valid CSS settings for the item that they will modify. For information on what types of values are valid, check the links included in the descriptions underneath the inputs.') . '</p>',
	);
	$form['display']['screen_fade_color'] = array
	(
	 	'#title' => t('Screen Fade Color'),
		'#type' => 'textfield',
		'#maxlength' => 7,
		'#size' => 8,
		'#default_value' => variable_get('screen_fade_color', 'white'),
		'#description' => t('This is the color that the screen fades to when the login box is activated. This should generally be black, white, or the same color as the background of your site. CSS property: !url.', array('!url' => '<a href="http://www.devguru.com/technologies/css2/8047.asp">background-color</a>')),
	);
	$form['display']['screen_fade_z_index'] = array
	(
		'#title' => t('Screen Fade z-index'),
		'#type' => 'textfield',
		'#maxlength' => 4,
		'#size' => 8,
		'#default_value' => variable_get('screen_fade_z_index', '10'),
		'#description' => t('This is the z-index of the faded screen. If you find elements on your layout are appearing over top of the faded out part of your screen, you can increase this number, but you should probably not touch it otherwise. CSS propery !url.', array('!url' => '<a href="http://www.devguru.com/technologies/css2/8139.asp">z-index</a>')),
	);
	$form['display']['login_box_background_color'] = array
	(
	 	'#title' => t('Login Box Background Color'),
		'#type' => 'textfield',
		'#maxlength' => 7,
		'#size' => 8,
		'#default_value' => variable_get('login_box_background_color', 'white'),
		'#description' => t('This is the background color of the login box. CSS property: !url.', array('!url' => '<a href="http://www.devguru.com/technologies/css2/8047.asp">background-color</a>')),
	);
	$form['display']['login_box_text_color'] = array
	(
	 	'#title' => t('Login Box Text Color'),
		'#type' => 'textfield',
		'#maxlength' => 7,
		'#size' => 8,
		'#default_value' => variable_get('login_box_text_color', 'black'),
		'#description' => t('This is the color of the text inside the login box. CSS property: !url.', array('!url' => '<a href="http://www.devguru.com/technologies/css2/8077.asp">color</a>')),
	);
	$form['display']['login_box_border_color'] = array
	(
	 	'#title' => t('Login Box Border Color'),
		'#type' => 'textfield',
		'#maxlength' => 7,
		'#size' => 8,
		'#default_value' => variable_get('login_box_border_color', 'black'),
		'#description' => t('This is the color of the border around the login box. CSS property: !url.', array('!url' => '<a href="http://www.devguru.com/technologies/css2/8057.asp">border-color</a>')),
	);
	$form['display']['login_box_border_width'] = array
	(
	 	'#title' => t('Login Box Border Width'),
		'#type' => 'textfield',
		'#maxlength' => 7,
		'#size' => 8,
		'#default_value' => variable_get('login_box_border_width', '3px'),
		'#description' => t('This is the width of the border around the login box. CSS property: !url.', array('!url' => '<a href="http://www.devguru.com/technologies/css2/8072.asp">border-width</a>')),
	);
	$form['display']['login_box_border_style'] = array
	(
	 	'#title' => t('Login Box Border Style'),
		'#type' => 'textfield',
		'#maxlength' => 7,
		'#size' => 8,
		'#default_value' => variable_get('login_box_border_style', 'solid'),
		'#description' => t('This is the style (eg: solid, dotted) of the border around the login box. CSS property: !url.', array('!url' => '<a href="http://www.devguru.com/technologies/css2/8067.asp">border-style</a>')),
	);
	$form['display']['fancy_login_hide_objects'] = array
	(
		'#title' => t('Hide Objects'),
		'#type' => 'checkbox',
		'#default_value' => variable_get('fancy_login_hide_objects', 0),
		'#description' => t('If you are having issues where the fancy login box is being hidden behind videos or other flash objects, check this box to hide the objects while the login box is being shown'),
	);
	$form['display']['fancy_login_dim_fade_speed'] = array
	(
		'#title' => t('Background Fade Speed'),
		'#type' => 'textfield',
		'#default_value' => variable_get('fancy_login_dim_fade_speed', 500),
		'#maxlength' => 4,
		'#size' => 8,
		'#description' => t('This is the number of milliseconds it will take for the fullscreen background color to fade in/out. The higher the number, the slower the fade process will be. The lower the number, the faster the fade.'),
	);
	$form['display']['fancy_login_box_fade_speed'] = array
	(
		'#title' => t('Login Box Fade Speed'),
		'#type' => 'textfield',
		'#default_value' => variable_get('fancy_login_box_fade_speed', 1000),
		'#maxlength' => 4,
		'#size' => 8,
		'#description' => t('This is the number of milliseconds it will take for the login box to fade in/out. The higher the number, the slower the fade process will be. The lower the number, the faster the fade.'),
	);
	$form['fancy_login_no_redirect'] = array
	(
		'#title' => t('Keep User on Same Page'),
		'#type' => 'checkbox',
		'#description' => t('If this box is checked, the user will not be redirected upon login, and will stay on the page from which the login link was clicked. If this box is unchecked, the user will be redirected according to the Drupal system settings'),
		'#default_value' => variable_get('fancy_login_no_redirect', 0),
	);
	$form['fancy_login_disable_registration'] = array
	(
		'#title' => t('Disable Fancy Login account registration'),
		'#type' => 'checkbox',
		'#default_value' => variable_get('fancy_login_disable_registration', 0),
		'#description' => t('The link to "Create new account" in the fancy login box by default loads the account registration form into the fancy login box. However, on sites with large account registration forms, this may be unwieldy. If this box is checked, the "Create new account" link will redirect the user to the account registration page, rather than loading the form in the popup.'),
	);
	$form['ssl'] = array
	(
		'#type' => 'fieldset',
		'#title' => t('SSL (Secure Login)'),
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
	);
	$form['ssl']['fancy_login_https'] = array
	(
		'#title' => t('Enable SSL (HTTPS)'),
		'#type' => 'checkbox',
		'#description' => t('If this box is checked, the form will be posted as encrypted data (HTTPS/SSL). Only use this if you have already set up an SSL certificate on your site, and have set up the login page as an encrypted page.'),
		'#default_value' => variable_get('fancy_login_https', 0),
	);
	$form['ssl']['fancy_login_icon_position'] = array
	(
		'#type' => 'radios',
		'#title' => t('Secure login icon position'),
		'#options' => array(t("Don't show icon"), t('Above the form'), t('Below the form')),
		'#default_value' => variable_get('fancy_login_icon_position', 0),
		'#description' => t("If SSL is turned on, turning this option on will display an icon indicating that the login is secure"), 
	);

	return system_settings_form($form);
}

/**
 * Validation function for the settings page
 */
function fancy_login_settings_validate($form, &$form_state)
{
	$test_values = array
	(
		'screen_fade_color' => 'Screen Fade Color',
		'screen_fade_z_index' => 'Screen Fade z-index',
		'login_box_background_color' => 'login_box_background_color',
		'login_box_text_color' => 'login_box_text_color',
		'login_box_border_color' => 'login_box_border_color',
		'login_box_border_width' => 'login_box_border_width',
		'login_box_border_style' => 'Login Box Border Style',
	);
	foreach($test_values as $machine=>$human)
	{
		if($form_state['values'][$machine] == '')
		{
			form_set_error($machine, t('!field must contain a value.', array('!field' => $human)));
		}
	}
	if(!is_numeric(trim($form_state['values']['fancy_login_dim_fade_speed'])))
	{
		form_set_error('fancy_login_dim_fade_speed', t('Background Fade Speed must contain a numeric value'));
	}
	if(!is_numeric(trim($form_state['values']['fancy_login_box_fade_speed'])))
	{
		form_set_error('fancy_login_box_fade_speed', t('Login Box Fade Speed must contain a numeric value'));
	}
}

/**
 * Page callback function for fancy_login/ajax/%
 *
 * This function performs the AJAX callback for fancy_login.js
 * which makes AJAX commands requesting different forms, and
 * inserting them into the Fancy Login login block.
 */
function fancy_login_ajax_callback($type)
{
	switch($type)
	{
		case "password":
			module_load_include('inc', 'user', 'user.pages');
			$form = drupal_get_form('fancy_login_user_pass');

			break;

		case "register":
			$form = drupal_get_form('fancy_login_user_register_form');

			break;

		case "login":
			$form = drupal_get_form('fancy_login_user_login_block');
			unset($form['#prefix'], $form['#suffix']);

			break;
	}

	$rendered_form = render($form);

	$scripts = drupal_add_js();
	if (!empty($scripts['settings']))
	{
		$settings = '<script type="text/javascript">jQuery.extend(Drupal.settings, ';
		$settings .= drupal_json_encode(call_user_func_array('array_merge_recursive', $scripts['settings']['data']));
		$settings .= ');</script>';
	}

	$return = array('content' => $rendered_form . $settings, 'status' => TRUE, 'type' => $type);

	die(drupal_json_output($return));
}
